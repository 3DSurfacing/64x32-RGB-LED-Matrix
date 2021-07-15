
// PUT YO HEXES HERE DAWG
const hexArr = []

const filterImgs = (arr) => {
    console.log(typeof arr[0])
    let frames = [];
    frameNum = 0
    for (let i = 0; i < arr.length; i + 2048) {
        frameNum++
         frames.push(`const unsigned short frame${frameNum}[2048] PROGMEM={`);
         frames.push(arr.splice(0, 2048));
         frames.push(`}; \n`);
    }
    const hexes = document.getElementById('hexes')

    hexes.innerHTML = frames;
    // console.log(frames)
}

filterImgs(hexArr);