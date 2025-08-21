(function () {
    for(let i =1 ; i<= 4; i++){
        let line = ''
        let k = 1;
        let l = 1;
        for(let j=1 ; j<= 7; j++){

                if(j >= 5 - i && j<= 3 + i  && l) {
                    line +=  i % 2 == 0 ? String.fromCharCode(64 + k) : k
                    k++
                    l = 0
                } else {
                    line += ' ' 
                    l = 1 
                }
        }
        console.log(line);
        
    }
})()