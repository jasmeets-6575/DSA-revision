(function (){
    for (let i = 1; i <=4 ; i++ ){
        let line  = ''; 
        let k = 0;
        let l = 1; 
        for (let j= 1; j <= 8; j++ ){
            if (j>= 5 - i && j <= 4 + i ) {
                if (j > 4) {
                    line += l
                    l++
                } else {
                    line += String.fromCharCode(65 + k);
                    k++
                }
            } else { 
                line += ' '
            }
        }
        console.log(line);
    }
})()