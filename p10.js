import React, { useState, useEffect } from 'react';

export default function App() {
  const [users, setUsers] = useState([]);
  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/users')
      .then(res => res.json())
      .then(data => setUsers(data)); 
  }, []);

  if (users.length === 0) return <h3>Loading...</h3>;

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