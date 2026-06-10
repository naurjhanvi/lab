import { useState } from 'react';
import './App.css';

function App() {
  const [query, setQuery] = useState('');
  const fruits = ['Apple', 'Banana', 'Orange', 'Grapes', 'Mango'];
  return (
    <div className="App">
      <input onChange={(e) => setQuery(e.target.value.toLowerCase())} />
      {fruits.filter(f => f.toLowerCase().includes(query)).map(f => <p key={f}>{f}</p>)}
    </div>
  );
}

export default App;
