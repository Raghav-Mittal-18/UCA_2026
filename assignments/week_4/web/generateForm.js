const fields = [
  "First Name",
  "Last Name",
  "Email"
];

function generateForm(fields) {
  return fields.map(field => `
<label>${field}</label>
<input type="text">
`).join('');
}

console.log(generateForm(fields));
