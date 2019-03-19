function getMarkdownTag() {
	// get first XMP tag (assuming it contains the markdown code)
	return document.getElementsByTagName('xmp')[0];
}

function convertMarkdownToHtml(markdownTag) {
	if( !markdownTag ) {
		return null;
	}

	return marked(markdownTag.innerText);
}

function insertMarkdownHtmlElement(markdownTag, markdownHtml) {
	var contentDiv = document.createElement('div');
	contentDiv.innerHTML = markdownHtml;
	markdownTag.parentNode.replaceChild(contentDiv, markdownTag);
	return contentDiv;
}

function processAllImages(htmlDiv) {
	var images = htmlDiv.getElementsByTagName('img');
	for( var i = 0; i < images.length; ++i ) {
		images[i].className += ' u-max-full-width';
	}
}

function processTables(htmlDiv) {
	var tables = htmlDiv.getElementsByTagName('table');
	for( var i = 0; i < tables.length; ++i ) {
		tables[i].className += ' table table-hover table-striped';
	}
}

function processCodeBlocks(htmlDiv) {
	var codes = htmlDiv.getElementsByTagName('code');

	for( var i = 0; i < codes.length; ++i ) {
		var language = codes[i].className;
		codes[i].className = 'prettyprint lang-' + language;
	}
	prettyPrint();
}

window.onload = function() {
	var markdownTag = getMarkdownTag();
	var markdownHtml = convertMarkdownToHtml(markdownTag);
	if( markdownHtml != null ) {
		var htmlDiv = insertMarkdownHtmlElement(markdownTag, markdownHtml);
		processAllImages(htmlDiv);
		processTables(htmlDiv);
		processCodeBlocks(htmlDiv);
	}
};
