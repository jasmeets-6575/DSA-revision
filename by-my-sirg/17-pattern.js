(function (){
    for (let i=1; i<= 5; i++) {
        let star = ''
        for (let j=1; j<= 9; j++) {
            if (j >= i  && j<= 10 - i) star += '*'
            else star += ' '
        }
        console.log(star);
    }
})()