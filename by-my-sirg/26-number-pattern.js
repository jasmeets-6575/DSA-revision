(function (){
    for (let i = 1; i <=4 ; i++ ){
        let line  = ''; 
        let k = 0
        for (let j= 1; j <= 7; j++ ){
            if( j >= 5 - i && j <= 3 + i ){
                line += k + i 
                j > 3 ? k++ : k--
            } else line += ' '
        }
        console.log(line);
    }
})()