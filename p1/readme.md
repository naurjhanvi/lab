# Experiment 1: MongoDB Data Insertion

## Prerequisites

- MongoDB Server installed and running
- MongoDB Compass installed
- Node.js and npm installed

---

## Step 1: Start MongoDB

Ensure your local MongoDB server is running.

1. Open **MongoDB Compass**.
2. Connect to:

```text
mongodb://localhost:27017
```

---

## Step 2: Create Project Files

Inside your lab/project folder, create the following files:

```text
transactions.json
transactions_upsert.json
p1.js
```

---

## Step 3: Add Dummy Data

Paste the provided JSON data into both files:

- `transactions.json`
- `transactions_upsert.json`

Save the files.

---

## Step 4: Install MongoDB Driver

Open a terminal and navigate to your project folder.

Run:

```bash
npm install mongodb
```

This command:

- Downloads the MongoDB Node.js driver
- Creates `package.json`
- Creates `package-lock.json`
- Downloads dependencies into the `node_modules` folder

---

## Step 5: Write the Program

Paste the JavaScript code into `p1.js`.

Make sure file paths are specified correctly:

```javascript
"./transactions.json"
```

This tells Node.js to look for the JSON file in the current directory.

---

## Step 6: Run the Script

Execute the program using:

```bash
node p1.js
```

If the script runs successfully, the data will be inserted into MongoDB.

---

## Step 7: Verify the Output

1. Open **MongoDB Compass**.
2. Refresh the connection.
3. Locate the database:

```text
usermanaged
```

4. Open the collection:

```text
transactions
```

5. Click the **Refresh** icon.

You should now see the inserted documents in the collection.

---

## Expected Result

- MongoDB connection established successfully.
- JSON data inserted into the `transactions` collection.
- Data visible in MongoDB Compass under the `usermanaged` database.