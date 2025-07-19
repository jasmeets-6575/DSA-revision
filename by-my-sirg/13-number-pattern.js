(
    function () {
        for (let i = 1; i <= 7; i++){
            let star = ''
            let k = 7 - i 
            for (let j = 0; j <= 7; j++){
                if(j <= 7- i ){
                    star += k
                    k--
                }
            }
            console.log(star);
        }
    }
)()