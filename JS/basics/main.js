const mysql = require('mysql2');

// Create a connection to the database
const connection = mysql.createConnection({
  host: '127.0.0.1',
  user: 'root',
  password: '2222',
  database: 'Parks_and_Recreation'
});

// Connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to the database:', err.stack);
    return;
  }

  console.log('Connected to the database.');

  // Query the employee_demographics table
  connection.query('SELECT * FROM employee_demographics', (error, results, fields) => {
    if (error) {
      console.error('Error executing query:', error.stack);
      return;
    }

    // Process the result set
    results.forEach(row => {
      console.log(`Age: ${row.age}, Birth Date: ${row.birth_date}, Employee ID: ${row.employee_id}, First Name: ${row.first_name}, Gender: ${row.gender}, Last Name: ${row.last_name}`);
    });

    // Close the connection
    connection.end((err) => {
      if (err) {
        console.error('Error closing the connection:', err.stack);
        return;
      }

      console.log('Connection closed.');
    });
  });
});
