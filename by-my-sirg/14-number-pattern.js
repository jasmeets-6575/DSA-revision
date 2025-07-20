(function () {
    for (let i = 1; i <= 9; i++) {
        let star = '';
        let k = 1;
        for (let j = 1; j <= 5; j++) {
        if (i <= 5) {
            if (j >= 6 - i) {
                star += k;
                k++;
            } else {
                star += ' ';
            }
        } else {
            if (j >= i - 4) {
                star += k;
            k++;
            } else {
            star += ' ';
            }
        }
        }
        console.log(star);
    }
})();
