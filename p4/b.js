const { MongoClient } = require("mongodb");

async function run() {
    const partialName = process.argv[2]; 

    const client = await MongoClient.connect("mongodb://127.0.0.1:27017");
    const col = client.db("college").collection("students");

    // $regex does the partial match, $options: "i" makes it case-insensitive
    const students = await col.find({ name: { $regex: partialName, $options: "i" } }).toArray();
    
    console.log("Search Results:", students);
    client.close();
}

run();