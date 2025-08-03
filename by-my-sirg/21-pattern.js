(function (){
    for (let i = 1; i <=4 ; i++ ){
        let star  = ''; 
        let k = 1;
        let l = 0;
        for (let j= 1; j <= 8; j++ ){
            if( j <= 4) {
                if(j>= 5 - i && j<= 4 + i){
                    star += k
                    k++
                } else {
                    star += ' '
                }
            } else {
                if (j <= 3 + i ) {
                    star += String.fromCharCode(65 + l)
                    l++
                } 
            }
        }
        console.log(star);
    }
})()