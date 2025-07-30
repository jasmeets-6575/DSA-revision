(function (){
    for (let i = 1; i <=4 ; i++ ){
        let star  = ''; 
        
        for (let j= 1; j <= 8; j++ ){
            if (j >=  5-i && j<= 9 - i) {
                    star += '*'
                } else {
                    star += ' '
                }
        }
        console.log(star);
    }
})()