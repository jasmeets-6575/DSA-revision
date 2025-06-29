(function () {
    for(let i =1 ; i<= 5; i++){
        let line = ''
        let k = 0;
        for(let j=1 ; j<= 5; j++){
                if (j<= i ) {
                    line += `${k} ` 
                    k += (i - 1)
                } else {
                    line += ' '
                }
        }
        console.log(line);
        
    }
})()