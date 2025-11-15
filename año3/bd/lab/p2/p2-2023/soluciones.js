use('supplies')
// // Ej1
// db.sales.find({
//     storeLocation: { $in: [ "London", "Austin", "San Diego" ] },
//     'customer.age': {$gte: 18},
//     items: {
//         $elemMatch: {
//             price: {
//                 $gte: Decimal128('1000.0'),
//             },
//             tags: {
//                 $in: ["school", "kids"]
//             }
//         }
//     }
// }, {
//     _id: 0,
//     sale: "$_id",
//     saleDate: 1,
//     storeLocation: 1,
//     clientEmail: "$customer.email"
// })

// // Ej2
db.sales.aggregate([
    {
        $match: {
            storeLocation: "Seattle",
            purchaseMethod: {
                $in: ["In Store", "Phone"]
            },
            saleDate: {
                $gte: new Date("2014-02-01"),
                $lte: new Date("2015-01-31")
            }
        }
    },
    {
        $unwind: '$items'
    },
    {
        $group: {
            _id: {
                sale_id: "$_id",
                email: "$customer.email",
                satisfaction: "$customer.satisfaction"
            },
            totalPrice: {
                $sum: {
                    $multiply: [
                        "$items.price",
                        "$items.quantity"
                    ]
                }
            }
        }
    }, {
        $project: {
            _id: 0,
            sale_id: "$_id.sale_id",
            email: "$_id.email",
            satisfaction: "$_id.satisfaction",
        }
    }, {
        $sort: {
            satisfaction: -1,
            email: 1
        }
    }
])
