<script lang="ts">
	import { onMount } from "svelte";


let files = []

let images = [];
let otherFiles = [];

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
        
        {#each images as file}
            <li>
                <img src="/public/{file.name}" alt="{file.name}" />
            </li>
        {/each}
    </ul>
    <h1>Autres fichiers</h1>
    <ul>
        {#each otherFiles as file}
            <li>
                <a href="/public/{file.name}">{file.name}</a>
            </li>
        {/each}
</section>