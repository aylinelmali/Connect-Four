function generateInput(n){
  let a = [];
  for(let i = 0; i < n; ++i){
    let arr = [];
    for(let j = 0; j < n; ++j){
      arr.push(j);
    }
    a.push(shuffle(arr));
  }
  return a;
}

function shuffle(a){
  for(let i = a.length - 1; i >= 1; --i){
    let j = Math.floor(Math.random()*(i+1));
    let tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
  return a;
}

function oracle(f){
  let numTests = 20;
  for(let i = 0; i < numTests; ++i){
    let n = 6;
    let companies = generateInput(n);
    let candidates = generateInput(n);
    let hires = f(companies, candidates);

    test('Hires length is correct', function(){
      assert(companies.length === hires.length);
    });

    test('Mutual first pick is correct', function(){
      for(let x = 0; x < companies.length; ++x){
        let y = companies[x][0];
        if(candidates[y][0] === x){
          assert(hiresContains(x, y, hires));
        } 
      }
    });

  }
}

oracle(wheat1);
oracle(chaff1);

function randomInt(min, max){
  return Math.floor(Math.random() * (max-min)) + min;
}

function hiresContains(m, n, hiresList){
  for(let i = 0; i < hiresList.length; ++i){
    if(hiresList[i].company === m && hiresList[i].candidate === n){return true;}
  }
  return false;
}