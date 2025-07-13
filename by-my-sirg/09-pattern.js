(function () {
    for (let i= 1 ; i <= 7; i++){
        let star = ''
        for (let j=1; j <= 7; j++) {
            if (i <= 4) {
            if ( j >4 -i && j < 4 + i) {
                star += '*';
            } else {
                star += ' '
            }
            } else { 
            if (i > 4 && j > i - 4 && j < 12 - i) { 
                star += '*' 
            } else star += ' '
        }
        }
        console.log(star);
        
    }
})()

(function () {
    let k = 0;
    for (let i = 1; i <= 7; i++) {
        let star = '';
        i <= 4 ? k++ : k--;
        for (let j = 1; j <= 7; j++) {
            if (j >= 5 - k && j <= 3 + k) {
                star += '*';
            } else {
                star += ' ';
            }
        }
        console.log(star);
    }
})();
