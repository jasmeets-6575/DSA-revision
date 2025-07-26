(function () {
    for (let i =1; i<= 7; i++) {
        let star = ''
        for (let j=1; j<= 7; j++) {
            if( j == i ) star += '\\'
            else if ( j == 8 - i && j!= 4) {
                star += '/'
            }
            else star += '*'
        }
        console.log(star); 
    }
})()