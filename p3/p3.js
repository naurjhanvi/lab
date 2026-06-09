async function run() {

    console.log("--- Part A: Cookies ---");
    const response = await fetch('https://google.com', { credentials: 'include' });
    console.log("Google Cookies:", response.headers.get('set-cookie'));

    console.log("\n--- Part B: Car Object ---");
    let car = { brand: "Toyota", model: "Camry", year: 2022, color: "Blue" };
    console.log("Before:", car);
    delete car[Object.keys(car)[1]]; 
    console.log("After:", car);
    console.log("Total Properties Left:", Object.keys(car).length);
}

run();