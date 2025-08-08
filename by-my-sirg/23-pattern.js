(function (){
    for (let i = 1; i <=7  ; i++ ){
        let line  = ''; 
        for (let j= 1; j <= 7; j++ ){
            if ( j == 4 && i == 4 || i == 2 && j > 1 && j< 7 || i == 6 && j > 1 && j< 7 || j ==2 && i > 1 && i < 7 || j == 6 && i > 1 && i < 7 ) {
                line += ' '
            } else line += '*'
        }
        console.log(line);
    }
})()