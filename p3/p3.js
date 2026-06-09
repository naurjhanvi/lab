async function run() {
    // --- PART A: Check Request Header for Cookies ---
    console.log("--- Part A: Cookies ---");
    const response = await fetch('https://google.com', { credentials: 'include' });
    console.log("Google Cookies:", response.headers.get('set-cookie'));

    // --- PART B: Car Object Operations ---
    console.log("\n--- Part B: Car Object ---");
    let car = { brand: "Toyota", model: "Camry", year: 2022, color: "Blue" };
    console.log("Before:", car);

    // Get the keys, find the 2nd one (index 1), and delete it
    delete car[Object.keys(car)[1]]; 

    console.log("After:", car);
    console.log("Total Properties Left:", Object.keys(car).length);
}

run();