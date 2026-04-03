const x = [[1,0,0,1],[0,1,1,0]];

let ok = true;
const nRobos = x[0].filter(v => v === 1).length;

for (let i = 0; i < x.length && ok; i++) {
    if (x[i].filter(v => v === 1).length !== nRobos) {
        ok = false;
        break;
    }
    if (i === 0) continue;

    const prev = [];
    const curr = [];

    for (let j = 0; j < x[i].length; j++) {
        if (x[i - 1][j] === 1) prev.push(j);
        if (x[i][j]     === 1) curr.push(j);
    }
    for (let h = 0; h < curr.length; h++) {
        if (Math.abs(prev[h] - curr[h]) > 1) {
            ok = false;
            break;
        }
    }
}
console.log(ok);