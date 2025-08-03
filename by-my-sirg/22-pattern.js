(function (){
    for (let i = 1; i <=6  ; i++ ){
        let line  = ''; 
        
        for (let j= 1; j <= 6; j++ ){
            if (j % 2 == 0 && j <= i) {
                line += '0'
            } else if (j% 2 && j <= i) line += '1'
            else line += ' '
        }
        console.log(line);
    }
})()