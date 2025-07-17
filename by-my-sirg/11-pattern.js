(function () {
    for(let i = 1; i <= 4; i++) {
        let star = '';
        for(let j = 1; j <= 7; j++) {
            if ( j >= i && j <= 8 - i ) {
                star += '*'
            } else star += ' '
        }
        console.log(star);
        
    }
})()