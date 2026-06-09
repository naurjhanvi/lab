import React, { useState } from 'react';

export default function App() {
  const [query, setQuery] = useState('');
  const fruits = ['Apple', 'Banana', 'Orange', 'Grapes', 'Mango'];

  return (
    <div style={{ padding: "20px" }}>
      <h2>React Search Filter</h2>
      <input 
        placeholder="Search fruits..." 
        onChange={(e) => setQuery(e.target.value.toLowerCase())} 
      />
      
      <ul>
        {fruits
          .filter(fruit => fruit.toLowerCase().includes(query))
          .map(fruit => <li key={fruit}>{fruit}</li>)}
      </ul>
    </div>
  );
}