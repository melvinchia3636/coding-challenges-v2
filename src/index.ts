const fs = require("fs");

const nice: string = fs.readFileSync("nice.ts").toString();
console.log(nice.split("\n").length);
