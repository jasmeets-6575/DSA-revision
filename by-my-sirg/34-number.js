(function () {
    let k = 1;
    for(let i =1 ; i<= 5; i++){
        let line = ''
        k = k + (6 -i)
        for(let j=1 ; j<= 5; j++){
                if (j<= i ) {
                    line += `${k} ` 
                } else {
                    line += ' '
                }
        }
        console.log(line);
    }
})()