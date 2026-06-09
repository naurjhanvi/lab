import React, { useState, useEffect } from 'react';

export default function App() {
  // 1. Create a state to hold our user data (starts as an empty array)
  const [users, setUsers] = useState([]);

  // 2. Fetch the data once when the app loads
  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/users')
      .then(res => res.json())
      .then(data => setUsers(data)); // Save the API data into our state
  }, []);

  // 3. If the array is still empty, show a loading message
  if (users.length === 0) return <h3>Loading...</h3>;

  // 4. Once data arrives, map through it and print the names and emails
  return (
    <div style={{ padding: "20px" }}>
      <h2>Users List</h2>
      <ul>
        {users.map(user => (
          <li key={user.id}>{user.name} - {user.email}</li>
        ))}
      </ul>
    </div>
  );
}