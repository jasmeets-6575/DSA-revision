(function () {
    for (let i = 1; i <= 5 ; i++){
        let star = ''; 
        let k= 1;
        for (let j = 1; j <= 9 ; j++){
            if (j > 5 - i && j < 5 + i && k) {
                star += '*'
                k = 0;
            } else {
                star += ' '
                k = 1;
            }
        }
        console.log(star);
        
    }
})()

const rows = 5;

for (let i = 1; i <= rows; i++) {
  let row = '';

  // Add leading spaces
  for (let space = 1; space <= rows - i; space++) {
    row += ' ';
  }

  // Add stars with space
  for (let star = 1; star <= i; star++) {
    row += '* ';
  }

  console.log(row.trimEnd()); // Remove trailing space for neatness
}
