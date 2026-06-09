const { MongoClient } = require("mongodb");

async function run() {
    const client = await MongoClient.connect("mongodb://127.0.0.1:27017");
    const col = client.db("usermanaged").collection("transactions");

    await col.drop().catch(() => {});
    await col.insertMany([
        { Name: "Somu", Payment: { Total: 600 }, Transaction: { price: 450 } },
        { Name: "John", Payment: { Total: 500 }, Transaction: { price: 350 } },
        { Name: "Alice", Payment: { Total: 300 }, Transaction: { price: 400 } }
    ]);

    console.log("1. Name = Somu:", await col.find({ Name: "Somu" }).toArray());
    
    console.log("2. Payment = 600:", await col.find({ "Payment.Total": 600 }).toArray());
    
    console.log("3. Price 300-500:", await col.find({ "Transaction.price": { $gte: 300, $lte: 500 } }).toArray());
    
    const agg = await col.aggregate([{ $group: { _id: null, total: { $sum: "$Payment.Total" } } }]).toArray();
    console.log("4. Total Payment:", agg[0].total);

    client.close();
}

run();