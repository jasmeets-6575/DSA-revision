function print() {
    for(let i =1; i <=5; i++){
        let star = ''
        for (let j=1; j<=5; j++) {
            if ( j <= 6 - i) {
                star += '*'
            } else {
                star += ' '
            }
        }
        console.log(star);
    }
}

print()