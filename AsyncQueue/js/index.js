class AsyncQueue {
    constructor() {
        this.running = 0;
        this.queue = [];
    }

    enqueue(promiseFactory) {
        return new Promise((resolve, reject) => {
            this.queue.push({
                promiseFactory,
                resolve,
                reject
            });
            this.run();
        });
    }

    async run() {
        if (this.running >= 3 || this.queue.length === 0) {
            return;
        }

        const task = this.queue.shift();
        this.running++;

        try {
            const result = await task.promiseFactory();
            task.resolve(result);
        } catch (error) {
            task.reject(error);
        } finally {
            this.running--;
            this.run();
        }
    }
}


const queue = new AsyncQueue();

const promiseFactory = () => {
    // your async request code here
    return new Promise((resolve, reject) => {
        // resolve or reject the promise here based on the result of the async request
    });
};

queue.enqueue(promiseFactory).then(result => {
    // handle the result of the async request here
}).catch(error => {
    // handle the error here
});
