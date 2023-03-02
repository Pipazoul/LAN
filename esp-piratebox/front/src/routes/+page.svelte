<script>
    import DisplayFiles from '$lib/components/DisplayFiles.svelte';
import FilesUpload from '$lib/components/FilesUpload.svelte';
import Nav from '$lib/components/Nav.svelte';
</script>
<section>
    <div class="p-4">
        <h2>Bienvenue</h2>
        <p>
            Inspiré du mouvement PirateBox, ce projet a pour but de créer un réseau de partage de fichiers et d'echange de message décentralisé.
            Il est basé sur un ESP32, une petite carte électronique peux couteuse (2-3 euros environ) qui permet de créer un réseau wifi.
            <br>Le projet est en court de développement ici https://github.com/Pipazoul/LAN
            <br>
            ################################ BUGS #####################################<br><br>
            Une fois l'image chargée attendre un peu le temps que l'image s'affiche puis cliquer sur "publier fichier" et raffraichir vore page qq secondes plus tard pour voir votre fichier
            Si la page ne s'affiche plus c'est que l'esp ,n'a pas tenu la charge est a crashé, mais il sera disponnible a nouveau quelqueq dizaines de secondes plus tard 
            <br>
        </p>
    </div>
    <FilesUpload />
    <DisplayFiles />
</section>
