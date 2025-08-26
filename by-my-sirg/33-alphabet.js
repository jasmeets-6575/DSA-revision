(function () {
    for(let i =1 ; i<= 4; i++){
        let line = ''
        let k = 1
        for(let j=1 ; j<= 7; j++){
                if (j<= 5 - i || j >= 3 + i ) {
                    line += String.fromCharCode(64 + k)
                } else {
                    line += ' '
                }
                k++
        }
        console.log(line);
        
    }
})()