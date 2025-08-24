(function () {
    for(let i =1 ; i<= 5; i++){
        let line = ''
        for(let j=1 ; j<= 5; j++){
                if (j== i || j == 6 - i ) {
                    line += '*'
                } else {
                    line += ' '
                }
        }
        console.log(line);
        
    }
})()