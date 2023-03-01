<script lang="ts">
	import { onMount } from "svelte";

    let storageSize = {
        used: 0,
        total: 0
    };

    onMount(async () => {
        // fetch storage size from server /storage
        fetch('/space').then(res => res.json())
        .then(data => {
            storageSize = data;
        });
    });

    $: storagePercentage = Math.round(storageSize.used / storageSize.total * 100);
    $:  storagePercentageString = storagePercentage + '%';
    // convert bytes to megabytes and round to 2 decimals
    $:  storageUsed = Math.round(storageSize.used / 1000000 * 100) / 100;
    $:  storageTotal = Math.round(storageSize.total / 1000000 * 100) / 100;

</script>
<nav class="flex bg-slate-500 p-5  flex justify-between">
    <h1 class="mr-4">ESP PirateBox</h1>
    <ul class="flex space-x-4">
    </ul>
    <div class="flex ml-4 justify-between w-1/5">
        <p>Stockage</p>
        <p>{storageUsed} / {storageTotal} Mo</p>
        <p>{storagePercentageString} utilisé</p>
    </div>
</nav>
