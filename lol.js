let value = {
  name: "lmao"
};

function changeValue(v) {
  v.name = "lmao2";
}

value.name = "lmao3"
changeValue(value)
console.log(value.name)