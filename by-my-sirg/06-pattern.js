(function (){
    for (let i = 1; i<= 5; i++){
        let star = '';
        for (let j = 1 ; j <= 9; j++){
            if ( j <= 6 - i || j >= 4 + i){
                star += '*'
            } else star += ' '
        }
        console.log(star);
    }
})()