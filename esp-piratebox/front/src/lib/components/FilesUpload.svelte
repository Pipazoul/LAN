<script lang="ts">

let  imageDisplay, fileinput;
	
const onFileSelected =(e)=>{
  console.log(e.target.files[0]);
  let image = e.target.files[0];
  let reader = new FileReader();
  reader.readAsDataURL(image);
  reader.onload = (e) => {
    // dither image
    compressImage(e.target.result);
  };
}

function compressImage(image) {
    // create a canvas element
    const canvas = document.createElement('canvas');
    const ctx = canvas.getContext('2d');
    
    // create an image object
    const img = new Image();
    img.crossOrigin = "anonymous"; // to avoid CORS issues
    
    // set the image source to the provided image url
    img.src = image;
    
    // wait for the image to load
    img.onload = function() {
        // set the canvas dimensions to the image dimensions
        let canvasWidth = img.width > 1000 ? 1000 : img.width;
        let canvasHeight = img.height * (canvasWidth / img.width);
        canvas.width = canvasWidth;
        canvas.height = canvasHeight;

        // draw the image on the canvas
        ctx.drawImage(img, 0, 0, canvasWidth, canvasHeight);
        
        // convert the image to black and white
        let imageData = ctx.getImageData(0, 0, canvasWidth, canvasHeight);
        let data = imageData.data;
        for (let i = 0; i < data.length; i += 4) {
            let avg = (data[i] + data[i + 1] + data[i + 2]) / 3;
            data[i] = avg;
            data[i + 1] = avg;
            data[i + 2] = avg;
        }
        ctx.putImageData(imageData, 0, 0);

        // convert the canvas to a data URL with webp format and 0.3 quality
        let dataURL = canvas.toDataURL('image/webp', 0.3);

        // set the imageDisplay variable to the compressed image data URL
        imageDisplay = dataURL;
    };
}


</script>
<section class="bg-slate-700 p-5">
	<h1>Charger une image</h1>
  {#if imageDisplay}
    <img src="{imageDisplay}" alt="d" />
  {:else}
    <p>Aucune Image</p>
  {/if}
  <input type="file" bind:this={fileinput} on:change={onFileSelected} />

  <button class="bg-red-400 rounded-xl p-4">publier l'image</button>
</section>
