(function (){
    for (let i = 1; i <=4 ; i++ ){
        let line  = ''; 
        let k = -1
        for (let j= 1; j <= 4; j++ ){
            if(j <= i){
                line += String.fromCharCode(65 + k + i)
                k--
            } else line += ' '
        }
        console.log(line);
    }
})()