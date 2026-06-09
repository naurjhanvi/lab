const express = require('express');
const app = express();

app.get('/find_prime_100', (req, res) => {
    let primes = [];
    for (let i = 2; i < 100; i++) 
        if (primes.every(p => i % p !== 0)) 
            primes.push(i);
    res.json({ primes });
});

app.get('/find_cube_100', (req, res) => {
    let cubes = [];
    for (let i = 1; i ** 3 < 100; i++) 
        cubes.push(i ** 3);
    res.json({ cubes });
});

app.listen(3000, () => console.log('Server running: http://localhost:3000'));