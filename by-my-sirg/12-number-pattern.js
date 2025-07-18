(
    function () {
        for (let i = 1; i <= 4; i++){
            let star = ''
            let k = i; 
            for (let j = 1; j <= 7; j++){
                if ( j >= 5 - i && j <= 3 + i ){
                    star += k
                    j<= 3 ? k++ : k--
                } else {
                    star += ' '
                }
            }
            console.log(star);
        }
    }
)()