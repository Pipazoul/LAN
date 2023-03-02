<script lang="ts">
	import { onMount } from "svelte";


let files = []

let images = [];
let otherFiles = [];

let currentImage = 0;

onMount(async () => {
    // fetch files from server /files
    fetch('/list').then(res => res.json())
    .then(data => {
        files = data;
    });
});

// sort files into two variables : images(wepb/jpg/png) and otherFiles(txt)
$: files.forEach(file => {
    if (file.name.endsWith('.webp') || file.name.endsWith('.jpg') || file.name.endsWith('.png')) {
         images = [...images, file];
    } else {
        otherFiles = [...otherFiles, file];
    }
});

</script>
<section>
    <h1>File list</h1>
    <h1>Images</h1>
    <ul>
        {#if images.length > 0}
            <img src="/public/{images[currentImage].name}" alt="d" />
            <button on:click={() => currentImage = currentImage === images.length - 1 ? 0 : currentImage + 1}>Next</button>
            <button on:click={() => currentImage = currentImage === 0 ? images.length - 1 : currentImage - 1}>Previous</button>
            {#each images as image, i}
                <ul>
                    <li on:click={() => currentImage = i}>{image.name}</li>
                </ul>
            {/each}
        {/if}
     
    </ul>
    <h1>Autres fichiers</h1>
    <ul>
        {#each otherFiles as file}
            <li>
                <a href="/public/{file.name}">{file.name}</a>
            </li>
        {/each}
</section>