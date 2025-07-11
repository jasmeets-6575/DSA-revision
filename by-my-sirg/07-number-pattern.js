(function (){
    for (let i = 1; i <=4 ; i++ ){
        let number = ''; 
        let k = 1;
        for (let j= 1; j <= 7; j++ ){
            if (j>= 5 - i && j <= 3 + i ) {
                number += k 
                j < 4 ? k++ : k--
            } else {number += ' '}
        }
        console.log(number);
    }
})()