use("university")
// ej1
db.grades.find({
    scores: {
        $elemMatch: {
            $and: [
                {$or: [
                    {type: 'exam', score: {$gte: 80}},
                    {type: 'quiz', score: {$gte: 90}}
                ]}
            ]
        },
        $not: {
            $elemMatch: {type: 'homework', score: {$lt: 90}}
        }
    }},
    {
    _id: 0
    }
)

// ej2
db.grades.aggregate([
    {
        $match: {
            class_id: { $in: [ 20, 220, 420 ] }
        }
    },
    {
        $project: {
            _id: 0,
            class_id: 1,
            student_id: 1,
            min_score: { $min: "$scores.score"},
            max_score: { $max: "$scores.score"},
            avg_score: { $avg: "$scores.score"}
        }
    },
    {
        $sort: {
            student_id: 1, class_id: 1
        }
    }
])

// ej3

db.grades.aggregate([
    {
        $project: {
            class_id: 1,
            exam_scores: {
                $filter: {
                    input: "$scores",
                    as: "score",
                    cond: { $eq: [ "$$score.type", "exam" ] }
                }
            },
            quiz_scores: {
                $filter: {
                    input: "$scores",
                    as: "score",
                    cond: { $eq: [ "$$score.type", "quiz" ] }
                }
            }
        }
    },
    { $unwind: "$exam_scores" },
    { $unwind: "$quiz_scores" },
    {
        $group: {
          _id: "$class_id",
          max_exam: { $max: "$exam_scores.score" },
          max_quiz: { $max: "$quiz_scores.score" }
        }
    },
    {
        $sort: {
            _id: 1
        }
    }
])

if (db.getCollectionNames().includes("top10students")) {
   db.top10students.drop();
}

db.createView(
    "top10students",
    "grades",
    [
        {
            $group: {
              _id: "$student_id",
              avg_per_class: {
                $addToSet: {
                    class: "$class_id",
                    avg_score: {$avg: "$scores.score"}
                }
              }

            }
        },
        {
            $project: {
                avg_grade: {
                    $avg: "$avg_per_class.avg_score"
                }
            }
        },
        {
            $sort: { avg_grade: -1 }
        },
        {
            $limit: 10
        }
    ]
)
db.top10students.find()

Ejercicio 5
db.grades.updateMany(
    { class_id: 339 },
    [
        {
            $set: {
                score_avg: { $avg: "$scores.score" },
                letter: {
                    $switch: {
                        branches: [
                            {
                                case: { $lt: ["$score_avg", 60] },
                                then: "NA"
                            },
                            {
                                case: { $lt: ["$score_avg", 80] },
                                then: "A"
                            },
                            {
                                case: { $lte: ["$score_avg", 100] },
                                then: "P"
                            }
                        ],
                        default: ""
                    }
                }
            }
        }
    ]
)
db.grades.find({
    class_id: 339,
    letter: "A"
})

Ejercicio 6

db.runCommand({
    collMod: "grades",
    validator: {
        $jsonSchema: {
            required: ["student_id", "scores", "class_id"],
            properties: {
                student_id: { bsonType: "int" },
                class_id: { bsonType: "int" },
                scores: {
                    bsonType: "array",
                    items: {
                        bsonType: "object",
                        properties: {
                            type: {
                                enum: ["exam", "quiz", "homework"]
                            },
                            score: {
                                bsonType: "double",
                                minimum: Double(0),
                                maximum: Double(100)
                            }

                        },
                        required: ["type", "score"]
                    }
                }
            }
        }
    }
})

db.grades.insertOne({
    student_id: 9999,
    class_id: 9999,
    scores: [
        {type: "Pepito", score: 99.0 }
    ]
})

db.grades.insertOne({
    student_id: "9999",
    class_id: 9999,
    scores: [
        {type: "exam", score: 99.0 }
    ]
})
