use('university')
// ej1
db.grades.aggregate([
    {
        $unwind: "$scores"
    },
    {
        $group: {
            _id: "$class_id",
            average_score: { $avg: "$scores.score" }
        }
    },
    {
        $lookup: {
            from: "grades",
            pipeline: [
                {
                    $group: {
                        _id: "$class_id",
                        avg_score_per_class: {
                            $addToSet: {
                                avg_score: { $avg: "$scores.score" }
                            }
                        }
                    }
                },
                {
                    $project: {
                        class_avg: {
                            $avg: "$avg_score_per_class.avg_score"
                        }
                    }
                },
                {
                    $group: {
                        _id: null,
                        total_avg: { $avg: "$class_avg" }
                    }
                }

            ],
            as: "overall_average"
        }
    },
    {
        $project: {
            _id: 0,
            class_id: "$_id",
            average_score: 1,
            overall_average: "$overall_average.total_avg",
            comparison_to_overall_average: {
                $switch: {
                    branches: [
                        {
                            case: { $lt: [
                                "$average_score",
                                {$arrayElemAt: ["$overall_average.total_avg", 0]},
                            ] },
                            then: "below"
                        },
                        {
                            case: { $gt: [
                                "$average_score",
                                {$arrayElemAt: ["$overall_average.total_avg", 0]},
                            ] },
                            then: "above"
                        },
                    ],
                    default: "equal"
                }

            }
        }
    },
    {
        $sort: {
            class_id: 1,
            average_score: -1,
        }
    }
])

// ej2
db.grades.updateMany(
    {},
    [
        {
            $set: {
                scores: {
                    $map: {
                        input: "$scores",
                        as: "score",
                        in: {
                            type: "$$score.type",
                            score: {
                                $multiply: [
                                    { $divide: ["$$score.score", 100] },
                                    7
                                ]
                            }
                        }
                    }
                }
            }
        }
    ]
);
db.grades.find({

})

// ej3
if (db.getCollectionNames().includes("top10students_homework")) {
   db.top10students_homework.drop();
}
db.createView(
    "top10students_homework",
    "grades",
    [
        {
            $project: {
                student_id: 1,
                class_id: 1,
                homework_scores: {
                    $filter: {
                        input: "$scores",
                        as: "score",
                        cond: { $eq: ["$$score.type", "homework"] }
                    }
                },
            }
        },
        {
            $unwind: "$homework_scores"
        },
        {
            $group: {
              _id: "$student_id",
              avg_homework_score: { $avg: "$homework_scores.score" }
            }
        },
        { $sort: { avg_homework_score: -1 } },
        { $limit: 10 },
    ]
)
db.top10students_homework.find({

})

// ej4
db.runCommand({
    collMod: "grades",
    validator: {
        $jsonSchema: {
            properties: {
                scores: {
                    bsonType: "array",
                    items: {
                        bsonType: "object",
                        required: ["type"],
                        properties: {
                            type: { enum: ["exam", "quiz", "homework"] }
                        }
                    }
                },
            }
        },
    }
})

