const canvas = document.getElementById('bordaCanvas');
const ctx = canvas.getContext('2d');
const resolution = 10;
const COLS = canvas.width / resolution;
const ROWS = canvas.height / resolution;
const candidates = ['A', 'B', 'C', 'D', 'E']; // Example candidates
let grid = initializeGrid();

function initializeGrid() {
    const grid = [];
    for (let i = 0; i < COLS; i++) {
        const column = [];
        for (let j = 0; j < ROWS; j++) {
            const randomIndex = Math.floor(Math.random() * votingData.length);
            column.push(votingData[randomIndex].slice()); // Copy the array to avoid reference issues
        }
        grid.push(column);
    }
    return grid;
}

function renderGrid() {
    ctx.clearRect(0, 0, canvas.width, canvas.height); // Clear canvas
    const pixelCountsElement = document.getElementById('pixelCounts');
    pixelCountsElement.innerHTML = ''; // Clear previous pixel counts
    const pixelCounts = calculatePixelCounts();

    for (let col = 0; col < COLS; col++) {
        for (let row = 0; row < ROWS; row++) {
            const cell = grid[col][row];
            const color = getColorFromRanking(cell[0]); // Use the top candidate for color representation
            ctx.fillStyle = color;
            ctx.fillRect(col * resolution, row * resolution, resolution, resolution);
        }
    }

    // Display pixel counts on the right side
    candidates.forEach((candidate, index) => {
        const count = pixelCounts[candidate];
        const candidateDiv = document.createElement('div');
        candidateDiv.textContent = `${candidate}: ${count / 100}`;
        candidateDiv.style.color = getColorFromRanking(candidate); // Set text color based on candidate
        pixelCountsElement.appendChild(candidateDiv);
    });
}

function calculatePixelCounts() {
    const pixelCounts = { 'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0 };

    for (let col = 0; col < COLS; col++) {
        for (let row = 0; row < ROWS; row++) {
            const cell = grid[col][row];
            const color = getColorFromRanking(cell[0]);
            if (color !== 'white') {
                pixelCounts[cell[0]] += resolution * resolution;
            }
        }
    }

    return pixelCounts;
}

function getColorFromRanking(candidate) {
    // Assign colors based on candidates
    switch (candidate) {
        case 'A':
            return '#227C9D';
        case 'B':
            return '#17C3B2';
        case 'C':
            return '#FFCB77';
        case 'D':
            return '#FEF9EF';
        case 'E':
            return '#FE6D73';
        default:
            return 'white';
    }
}

function calculateBordaScores(x, y) {
    const bordaScores = { 'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0 }; // Initialize Borda scores

    // Calculate Borda scores based on neighbors
    for (let i = -1; i <= 1; i++) {
        for (let j = -1; j <= 1; j++) {
            const neighborX = x + i;
            const neighborY = y + j;
            if (neighborX >= 0 && neighborX < COLS && neighborY >= 0 && neighborY < ROWS) {
                const neighborRanking = grid[neighborX][neighborY];
                for (let k = 0; k < candidates.length; k++) {
                    const candidate = candidates[k];
                    bordaScores[candidate] += calculateBordaPoints(neighborRanking.indexOf(candidate), k);
                }
            }
        }
    }

    return bordaScores;
}

function calculateBordaPoints(rankIndex, position) {
    // Borda points calculation, higher points for higher rank positions
    return candidates.length - 1 - rankIndex;
}

function updateGrid() {
    const nextGrid = [];

    // Update rankings based on Borda scores
    for (let col = 0; col < COLS; col++) {
        const column = [];
        for (let row = 0; row < ROWS; row++) {
            const bordaScores = calculateBordaScores(col, row);
            const sortedCandidates = candidates.slice().sort((a, b) => bordaScores[b] - bordaScores[a]); // Sort candidates by Borda scores
            column.push(sortedCandidates);
        }
        nextGrid.push(column);
    }

    grid = nextGrid;
}

function simulateElection() {
    setInterval(() => {
        updateGrid();
        renderGrid();
    }, 1000 / 5); // Adjust frame rate (lower value for faster animation)
}

simulateElection();
