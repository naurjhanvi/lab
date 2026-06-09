const fs = require('fs/promises');

async function run() {
    const file = "test.txt";

    // 1. Create (Write a new file)
    await fs.writeFile(file, "Hello ");
    console.log("Created file.");

    // 2. Read (Read the file contents)
    console.log("Read:", await fs.readFile(file, "utf8"));

    // 3. Update (Append new text to the existing file)
    await fs.appendFile(file, "World!");
    console.log("Updated Read:", await fs.readFile(file, "utf8"));

    // 4. Delete (Remove the file entirely)
    await fs.unlink(file);
    console.log("Deleted file.");
}

run();