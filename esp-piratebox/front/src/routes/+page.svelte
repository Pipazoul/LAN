<script>
    import DisplayFiles from '$lib/components/DisplayFiles.svelte';
import FilesUpload from '$lib/components/FilesUpload.svelte';
import Nav from '$lib/components/Nav.svelte';
</script>
<section>
    <div>
        <h2>Bienvenue</h2>
        <p>
            Inspiré du mouvement PirateBox, ce projet a pour but de créer un réseau de partage de fichiers et d'echange de message décentralisé.
            Il est basé sur un ESP32, une petite carte électronique peux couteuse (2-3 euros environ) qui permet de créer un réseau wifi.
            Le projet est open source et librement accessible. Vous pouvez le télécharger et le modifier à votre guise.
        </p>
    </div>
    <FilesUpload />
    <DisplayFiles />
</section>
