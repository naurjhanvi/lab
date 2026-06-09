const { MongoClient } = require("mongodb");

async function run() {
    const client = await MongoClient.connect("mongodb://127.0.0.1:27017");
    const col = client.db("college").collection("students");

    await col.drop().catch(() => {}); 
    const result = await col.insertMany(require("./data.json"));

    console.log(`Inserted ${result.insertedCount} students successfully!`);
    client.close();
}

run();