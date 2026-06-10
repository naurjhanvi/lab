const fs = require('fs/promises');

async function run() {
    const file = "test.txt";

    await fs.writeFile(file, "Hello ");
    console.log("Created file.");

    console.log("Read:", await fs.readFile(file, "utf8"));

    await fs.appendFile(file, "World!");
    console.log("Updated Read:", await fs.readFile(file, "utf8"));

    await fs.unlink(file);
    console.log("Deleted file.");
}

run();