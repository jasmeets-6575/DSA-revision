(function () {
    let k = -1
    for ( let i = 1; i <= 5; i ++) {
        let line = ''
        k = k+ 2 * (i - 1) + 1
        for ( let j = 1; j <= 5; j ++) {
            if (j>= 6 - i) {
                line += String.fromCharCode(65+k)
                k--
            } else line += ' '
        }
        console.log(line);
        
    }
})()