(function (){
    for (let i=1; i<= 9; i++) {
        let star = ''
        for (let j=1; j<= 9; j++) {
            if( i<=5) {
                if(j<= 5 - i || j >= 5 + i){
                    star += '*'
                } else { star += ' ' }
            } else {
                if (j <= i - 4 || j >= 14 - i) {
                    star += '*'
                } else {star += ' '}
            }
        }
        console.log(star);
    }
})()