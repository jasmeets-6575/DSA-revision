(function (){
    let n = 11; 
    let m = 0;
    for(let i = 1; i <= 21; i++){
        let line = '';
        i <= n ? m++ : m--
        let k = m
        for(let j = 1; j<= 21; j++){
            if( j>= n + 1 - m && j <= n - 1 + m ) {
                line += (k % 10)
                j<n ? k++ : k--
            } else line += ' '
        }
        console.log(line);
    }
})()